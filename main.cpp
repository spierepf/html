#include <iostream>
#include <string>
#include <vector>

#include "html.h"

using namespace std;

HTMLNode head(string title) {
    return
        HTMLNode("head")
            .addContent(HTMLNode("title").addContent(title))
            .addContent(HTMLNode("meta").addAttribute("charset", "utf-8"))
            .addContent(HTMLNode("meta").addAttribute("name", "viewport").addAttribute("content", "width=device-width, initial-scale=1"))
            .addContent(HTMLNode("link").addAttribute("rel", "stylesheet").addAttribute("href", "https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css"))
            .addContent(HTMLNode("script").addAttribute("src", "https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js").addContent(" "))
            .addContent(HTMLNode("script").addAttribute("src", "https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js").addContent(" "))
            .addContent(HTMLNode("style")
                .addContent("/* Set height of the grid so .sidenav can be 100% (adjust as needed) */")
                .addContent(".row.content {height: 550px}")
                .addContent("")
                .addContent("/* Set gray background color and 100% height */")
                .addContent(".sidenav {")
                .addContent("  background-color: #f1f1f1;")
                .addContent("  height: 100%;")
                .addContent("}")
                .addContent("")
                .addContent("/* On small screens, set height to 'auto' for the grid */")
                .addContent("@media screen and (max-width: 767px) {")
                .addContent("  .row.content {height: auto;}")
                .addContent("}\n")
            );
}

HTMLNode menuItem(string name, string href="#", bool isActive=false) {
    HTMLNode retval("li");
    if(isActive) retval.addAttribute("class", "active");
    retval.addContent(HTMLNode("a").addAttribute("href", href).addContent(name));
    return retval;
}

struct MenuItem {
    string name;
    string href;

    MenuItem(string name, string href = "#") : name(name), href(href) {}
};

HTMLNode menu(vector<MenuItem> items, int activeIndex) {
    HTMLNode retval("ul");
    for (int i = 0; i < items.size(); ++i) {
        retval.addContent(menuItem(items[i].name, items[i].href, activeIndex == i));
    }
    return retval;
}

int main() {
    vector<MenuItem> menuItems;
    menuItems.push_back(MenuItem("Dashboard"));
    menuItems.push_back(MenuItem("Age"));
    menuItems.push_back(MenuItem("Gender"));
    menuItems.push_back(MenuItem("Geo"));

    cout << (string)HTMLNode()
        .addContent("<!DOCTYPE html>")
        .addContent(HTMLNode("html").addAttribute("lang", "en")
            .addContent(head("Bootstrap Example"))
            .addContent(HTMLNode("body")
                .addContent(HTMLNode("nav"
                    ).addAttribute("class", "navbar navbar-inverse visible-xs")
                    .addContent(HTMLNode("div").addAttribute("class", "container-fluid")
                        .addContent(HTMLNode("div").addAttribute("class", "navbar-header")
                            .addContent(HTMLNode("button").addAttribute("type", "button").addAttribute("class", "navbar-toggle").addAttribute("data-toggle", "collapse").addAttribute("data-target", "#myNavbar")
                                .addContent(HTMLNode("span").addAttribute("class", "icon-bar").addContent(" "))
                                .addContent(HTMLNode("span").addAttribute("class", "icon-bar").addContent(" "))
                                .addContent(HTMLNode("span").addAttribute("class", "icon-bar").addContent(" "))
                            )
                            .addContent(HTMLNode("a").addAttribute("class", "navbar-brand").addAttribute("href", "#").addContent("Logo"))
                        )                              
                        .addContent(HTMLNode("div").addAttribute("class", "collapse navbar-collapse").addAttribute("id", "myNavbar")
                            .addContent(menu(menuItems, 0).addAttribute("class", "nav navbar-nav"))
                        )
                    )
                )
                .addContent(HTMLNode("div").addAttribute("class", "container-fluid")
                    .addContent(HTMLNode("div").addAttribute("class", "row content")
                        .addContent(HTMLNode("div").addAttribute("class", "col-sm-3 sidenav hidden-xs")
                            .addContent(HTMLNode("h2").addContent("Logo"))
                            .addContent(menu(menuItems, 0).addAttribute("class", "nav nav-pills nav-stacked"))
                            .addContent(HTMLNode("br"))
                        )
                        .addContent(HTMLNode("br"))
                        .addContent(HTMLNode("div").addAttribute("class", "col-sm-9")
                            .addContent(HTMLNode("div").addAttribute("class", "well")
                                .addContent(HTMLNode("h4").addContent("Dashboard"))
                                .addContent(HTMLNode("p").addContent("Some text.."))
                            )
                            .addContent(HTMLNode("div").addAttribute("class", "row")
                                .addContent(HTMLNode("div").addAttribute("class", "col-sm-3")
                                    .addContent(HTMLNode("div").addAttribute("class", "alert alert-success")
                                        .addContent(HTMLNode("h4").addContent("Users"))
                                        .addContent(HTMLNode("p").addContent("1 Million"))
                                    )
                                )
                                .addContent(HTMLNode("div").addAttribute("class", "col-sm-3")
                                    .addContent(HTMLNode("div").addAttribute("class", "alert alert-info")
                                        .addContent(HTMLNode("h4").addContent("Pages"))
                                        .addContent(HTMLNode("p").addContent("100 Million"))
                                    )
                                )
                                .addContent(HTMLNode("div").addAttribute("class", "col-sm-3")
                                    .addContent(HTMLNode("div").addAttribute("class", "alert alert-warning")
                                        .addContent(HTMLNode("h4").addContent("Sessions"))
                                        .addContent(HTMLNode("p").addContent("10 Million"))
                                    )
                                )
                                .addContent(HTMLNode("div").addAttribute("class", "col-sm-3")
                                    .addContent(HTMLNode("div").addAttribute("class", "alert alert-danger")
                                        .addContent(HTMLNode("h4").addContent("Bounce"))
                                        .addContent(HTMLNode("p").addContent("30%"))
                                    )
                                )
                            )
                            .addContent(HTMLNode("div").addAttribute("class", "row")
                                .addContent(HTMLNode("div").addAttribute("class", "col-sm-4")
                                    .addContent(HTMLNode("div").addAttribute("class", "well")
                                        .addContent(HTMLNode("p").addContent("Text"))
                                        .addContent(HTMLNode("p").addContent("Text"))
                                        .addContent(HTMLNode("p").addContent("Text"))
                                    )
                                )
                                .addContent(HTMLNode("div").addAttribute("class", "col-sm-4")
                                    .addContent(HTMLNode("div").addAttribute("class", "well")
                                        .addContent(HTMLNode("p").addContent("Text"))
                                        .addContent(HTMLNode("p").addContent("Text"))
                                        .addContent(HTMLNode("p").addContent("Text"))
                                    )
                                )
                                .addContent(HTMLNode("div").addAttribute("class", "col-sm-4")
                                    .addContent(HTMLNode("div").addAttribute("class", "well")
                                        .addContent(HTMLNode("p").addContent("Text"))
                                        .addContent(HTMLNode("p").addContent("Text"))
                                        .addContent(HTMLNode("p").addContent("Text"))
                                    )
                                )
                            )
                            .addContent(HTMLNode("div").addAttribute("class", "row")
                                .addContent(HTMLNode("div").addAttribute("class", "col-sm-8")
                                    .addContent(HTMLNode("div").addAttribute("class", "well")
                                        .addContent(HTMLNode("p").addContent("Text"))
                                    )
                                )
                                .addContent(HTMLNode("div").addAttribute("class", "col-sm-4")
                                    .addContent(HTMLNode("div").addAttribute("class", "well")
                                        .addContent(HTMLNode("p").addContent("Text"))
                                    )
                                )
                            )
                        )
                    )
                )
            )
        ) << endl;
}

