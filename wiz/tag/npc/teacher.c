#include <ansi.h>

inherit NPC;

void create()
{
    set_name("刘文章", ({ "liu wenzhang" }) );
    set("gender", "男性");
    set("age", 62);
    set("nick", "$HIW$学海无涯苦作舟$NOR$");
    set("long",
    "刘文章是仁义庄里最饱学之士，他出自书香门第。但他少年的时候，全家\n"
    "遭到屠杀，只有他一个人活了下来。\n"
    );

    set("inquiry", ([
        "here" : "这里便是仁义庄的学堂啊，这位*可有什么事情？\n" ,
        "rumors" : "哈哈，老朽多年不闻江湖事，*还是去找他人问吧。\n" ,
        "name" : "老朽乃是刘文章。\n" ,
        "刘文章" : "老朽便是刘文章，这位*找老朽可有什么事情？\n" ,
    ]));

    set("attitude", "peaceful");
    set("str", 25); 
    set("con", 20); 
    set("kar", 20); 
    set("cor", 15); 
    set("int", 80); 
    set("per", 25); 
    set("combat_exp", 500000); 
    set("max_kee",2000);
    set("max_gin",1000);
    set("max_sen",1000);
    set("force",200);
    set("max_force",200);
    set("force_factor",0);

    set_skill("literate", 300);


    setup();
    carry_object(ARMOR_DIR"cloth")->wear();
}
