// huashan shinv.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("侍女", ({ "shi nv" }) );
	
	set("gender", "女性" );
	set("age", 15);
	set("str", 20);
	set("per", 30);
	set("long", @LONG
她身着一袭青色的长裙，半长的头发盘在头
上，从装束上看是大户人家的丫鬟。她不时
抬头看你一眼，很有点俏皮。
LONG
);

	set("max_gin",3000);
	set("max_kee",3000);
	set("max_sen",3000);
	set("max_force",5000);
	set("force",5000);
	set("force_factor",200);

	set("combat_exp", 150000);
	set("attitude", "friendly");
        
        set_skill("unarmed", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
        set_skill("sword", 80);
        set_skill("force", 80);
        set_skill("dugu-sword", 80);
        set_skill("literate", 60);
        set_skill("zixia-force", 80);
        set_skill("lingyun-steps", 60);
        set_skill("fuyunshou", 60);
        map_skill("unarmed", "fuyunshou");
        map_skill("sword", "dugu-sword");
        map_skill("force", "zixia-force");
        map_skill("dodge", "lingyun-steps");

	set("inquiry", ([
              "华山":"华山？这周围近百里都是华山。",
              "华山派" : "你找找吧，不远了。",
              "拜师"   : "我干嘛要教你呢？",
              "name": "你好无聊，我干嘛要告诉你呢？",
              "风清杨":"你想知道点什么呢？",
              "here": "这里便是华山。",
              //"古琴曲" : (: feng_str :),
]) );
            
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
	    (: perform_action, "sword.yujian" :),
            (: perform_action, "sword.dang" :),
            (: perform_action, "sword.pojian" :),
            (: exert_function, "recover" :),
	}) );

	setup();
	
	carry_object(__DIR__"obj/erskirt")->wear();
	carry_object(__DIR__"obj/sword")->wield();
}