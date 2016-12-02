#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "../html.h"

TEST_CASE( "starts blank" ) {
    REQUIRE( (std::string)(HTMLNode()) == "" );
}

TEST_CASE( "empty node" ) {
    REQUIRE( (std::string)(HTMLNode("html")) == "<html/>" );
}

TEST_CASE( "node with single row content" ) {
    REQUIRE( (std::string)(HTMLNode("html").addContent("head")) == "<html>head</html>" );
}

TEST_CASE( "node with multirow content" ) {
    REQUIRE( (std::string)(HTMLNode("html").addContent("head\nbody")) == "<html>\n  head\n  body\n</html>" );
}

TEST_CASE( "node with attribute" ) {
    REQUIRE( (std::string)(HTMLNode("html").addAttribute("lang", "en")) == "<html lang=\"en\"/>" );    
}

TEST_CASE( "node with children" ) {
    REQUIRE( (std::string)(HTMLNode("html").addContent(HTMLNode("head")).addContent(HTMLNode("body"))) == "<html>\n  <head/>\n  <body/>\n</html>" );
}

TEST_CASE( "content only" ) {
    REQUIRE( (std::string)(HTMLNode().addContent("<!DOCTYPE html>")) == "<!DOCTYPE html>" );   
}

TEST_CASE( "content and node" ) {
    REQUIRE( (std::string)(HTMLNode().addContent("<!DOCTYPE html>").addContent(HTMLNode("html"))) == "<!DOCTYPE html>\n<html/>" );   
}
