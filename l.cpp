
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
namespace Lexer
{
    enum class TokenType 
    {
    PLUS,           
    MINUS,          
    ASTERISK,      
    SLASH,          
    EQUAL,          
    SEMICOLON,      
    COMMA,          
    DOT,            
    LEFT_PAREN,     
    RIGHT_PAREN,  
    LEFT_BRACE,    
    RIGHT_BRACE,    
    IDENTIFIER,     
    NUMBER,         
    STRING_LITERAL, 
    LET,           
    FN,             
    IF,            
    ELSE,           
    RETURN,        
    END_OF_FILE,    
    ILLEGAL         
};
struct Token
{
    std::string m;
    TokenType lol;
};
struct SyntaxTree
{
    std::vector<Token> o; 
   
};
    SyntaxTree tokenize(std::string m, Token o[])
    {
        SyntaxTree lol;
        int i; 
        while(true)
        {
            i++;
            switch(m.find(o[i].m) != std::string::npos)
            {
                case true:
                    lol.o[i] = o[i];
                case false:
                    break;
            }
        }
    }
    struct Node
    {
        Token l;
        int pos;
    };
    struct ASTNode {
        TokenType type;
        std::string value;  
        std::vector<std::unique_ptr<ASTNode> > children;

        ASTNode(TokenType type, const std::string& value)
            : type(type), value(value) {}
    };

    void parser(ASTNode lol, int recursion)
    {  
        int recursion;
        switch(lol.children.type)
        {
            case TokenType::PLUS:
                lol.value = lol.value + lol.children[recursion++].value;
            case TokenType::MINUS:
                lol.value = lol.value - lol.children[recursion++].value;
            case TokenType::ASTERISK:
                parser(lol, recursion++);
            case TokenType::SLASH:
                parser(lol, recursion++);
            case TokenType::EQUAL:
                lol.value = lol.children[recursion++];
            case TokenType::SEMICOLON:
                parser(lol.children[recursion], 0);
            case TokenType::COMMA:
                parser(lol.children[recursion], 0);
            case TokenType::DOT:

            case TokenType::LEFT_PAREN:
            case TokenType::RIGHT_PAREN:
            case TokenType::LEFT_BRACE:
            case TokenType::RIGHT_BRACE:
            case TokenType::IDENTIFIER:
                break;
            case TokenType::NUMBER:
                lol.value = lol.value + lol.children[recursion].value;
            case TokenType::STRING_LITERAL:
                break;
            case TokenType::LET:
                break;
            case TokenType::FN:
                break;
            case TokenType::IF:
                break;
            case TokenType::ELSE:
                break;
            case TokenType::RETURN:
                break;
            case TokenType::END_OF_FILE:
                break;
            case TokenType::ILLEGAL:
                break;
          break;
        }
    }
}
