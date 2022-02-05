#ifndef __LIBRARIES_H__
#define __LIBRARIES_H__

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

struct Comment
{
    string username;
    string text;
};

struct DiscountCode
{
    string code;
    float percentage;
};

#define SPACE ' '
#define COMMA ','
#define TV_INDICATOR 0
#define CAR_INDICATOR 1
#define MOBILE_INDICATOR 2
#define STARTING_ID_NUMBER 1
#define ADMIN_ID 0
#define ADMIN_USERNAE "admin"
#define ADMIN_PASSWORD "admin"
#define ADMIN_EMAIL "admin@gmail.com"
#define ADMIN_TYPE 0
#define SELLER_TYPE 1
#define BUYER_TYPE 2
#define NO_USER_LOGGED_IN -1
#define NOT_FOUND -1
#define ASCEND 1
#define DESCEND 0
#define lenOfDiscountCode 5
#define HUNDRED 100
#define WITHOUT_DISCOUNT 1
#define EMPTY_CART "Empty\n"
#define QUESTION_MARK "?"
#define DIVIDER " | "
#define NEXT_LINE "\n"
#define ORDER_DIVIDER "****\n"
#define GET_PRODUCTS_TITLE "productId | productName\n"
#define OK "OK\n"
#define OFFERS_TITLE "productId | productName | offerId | offerUnitPrice | offerAmount\n"
#define WALLET_TITLE "productId | offerId | offerUnitPrice | offerAmount\n"
#define ADMIN_OFFERS_TITLE "productId | offerId | offerUnitPrice | offerAmount\n"
#define OFFERS_ON_PRODUCT_TITLE "productId | productName | offerId | offerUnitPrice | offerAmount\n"
#define CART_TITLE "productId | productName | offerId | sellerId | totalPriceConsideringDiscount | amount\n"
#define ORDERS_TITLE "productId | productName | offerId | sellerId | soldPrice | amount\n"
#endif