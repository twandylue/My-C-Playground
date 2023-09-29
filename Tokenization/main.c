#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum TokenKind {
  Sym,
  Equal,
  Comma,
  OpenPare,
  ClosePare,
  OpenBrace,
  CloseBrace,
};

struct Token {
  enum TokenKind kind;
  char *text;
};

struct Lexer {
  char *source;
  int index;
};

struct Lexer *create_lexer(char *source) {
  struct Lexer *lexer = malloc(sizeof(struct Lexer));
  lexer->source = source;
  lexer->index = 0;
  return lexer;
}

struct Token *next_lexer(struct Lexer *lexer) {
  struct Token *token = malloc(sizeof(struct Token));
  char c = lexer->source[lexer->index];
  while (c == ' ') {
    lexer->index++;
    c = lexer->source[lexer->index];
  }

  switch (c) {
  case '=':
    token->kind = Equal;
    token->text = "=";
    break;
  case '(':
    token->kind = OpenPare;
    token->text = "(";
    break;
  case ')':
    token->kind = ClosePare;
    token->text = ")";
    break;
  case '{':
    token->kind = OpenBrace;
    token->text = "{";
    break;
  case '}':
    token->kind = CloseBrace;
    token->text = "}";
    break;
  case ',':
    token->kind = Comma;
    token->text = ",";
    break;
  default: {
    size_t s = lexer->index;
    while (isalpha(lexer->source[lexer->index]) != 0) {
      lexer->index++;
    }

    char *dest = malloc(lexer->index - s + 1);
    strncpy(dest, lexer->source + s, lexer->index - s);
    dest[lexer->index - s] = '\0';
    token->kind = Sym;
    token->text = dest;
    return token;
    break;
  }
  }

  lexer->index++;
  return token;
}

char *to_string(struct Token *token) {
  switch (token->kind) {
  case Sym:
    return "Sym";
  case Equal:
    return "Equal";
  case Comma:
    return "Comma";
  case OpenPare:
    return "OpenPare";
  case ClosePare:
    return "ClosePare";
  case OpenBrace:
    return "OpenBrace";
  case CloseBrace:
    return "CloseBrace";
  default:
    return "Unknown";
  }
}

int main(void) {
  struct Lexer *le = create_lexer("fn(   a   ) { test = abc }");
  while (le->index < (int)strlen(le->source)) {
    struct Token *token = next_lexer(le);
    printf("token text: %s\n", token->text);
    printf("token: %s\n", to_string(token));
    printf("-------\n");
  }

  return 0;
}
