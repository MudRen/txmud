// huashan yello-girl.c

#include <ansi.h>
inherit NPC;

string ask_feng(object who);

void create()
{
	set_name("黄衣少女", ({ "yellow girl" }) );
	set("title", HIY"流云仙子"NOR);
	set("gender", "女性" );

	set("age", 16);
	set("str", 20);
	set("per", 30);

	set("max_gin",3000);
	set("max_kee",3000);
	set("max_sen",3000);
	set("max_force",5000);
	set("force",5000);
	set("force_factor",200);

	set("long", @LONG
她身着一袭米黄色的长裙，飘逸的长发
用一条黄丝带系住。眉宇间带着一点忧
郁。她常在黄昏时来这里抚一把古琴。
LONG
);
	set("combat_exp", 500000);
	set("attitude", "friendly");
        
        set_skill("unarmed", 160);
	set_skill("parry", 160);
	set_skill("dodge", 160);
        set_skill("sword", 180);
        set_skill("force", 180);
        set_skill("huashan-sword", 180);
        set_skill("literate", 160);
        set_skill("zixia-force", 180);
        set_skill("lingyun-steps", 160);
        set_skill("fuyunshou", 160);
        map_skill("unarmed", "fuyunshou");
        map_skill("sword", "huashan-sword");
        map_skill("force", "zixia-force");
        map_skill("dodge", "lingyun-steps");

        set("inquiry", ([
              "华山":"华山？这周围近百里都是华山。",
              "华山派" : "你找找吧，不远了。",
              "风清杨": (: ask_feng :),
              //"古琴曲" : (: feng_str :),
]) );

/*
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yujian" :),
		(: perform_action, "sword.dang" :),
		(: perform_action, "sword.pojian" :),
		(: exert_function, "recover" :),
	}) );
*/

	setup();
	
	carry_object(__DIR__"obj/erskirt")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}

string ask_feng(object who)
{
	if(who->query_temp("asked_yg_about_feng"))
		return "不是都和你说了呀，帮我摘个桃子你都不干，嘻嘻。";

	if(!who->query_temp("asked_lh_about_feng"))
		return 0;

	who->delete_temp("asked_lh_about_feng");
	who->set_temp("asked_yg_about_feng",1);
	return "风老前辈隐居的时候我还没出世那，我怎么会知道。告诉你
个事：咱们紫霞宫桃林里的青山桃可是好东西，你要是能帮
我摘一颗，我就告诉你一件奇怪的事情。对啦，那些桃树春
秋两季节都会结果的。";
}

int accept_object(object who, object ob)
{
	if(base_name(ob) != "/d/huashan_zx/obj/tao")
		return 0;

	if(!who->query_temp("asked_yg_about_feng"))
	{
		write("黄衣少女说道：你怎么知道我喜欢吃桃子呀，谢谢啦！\n");
		return 1;
	}

	who->delete_temp("asked_yg_about_feng");
	write("黄衣少女告诉你说：谢谢你啦！我上次去晚上思过崖玩，站在松树上
    看月亮，借着月光看到悬崖上好像有个山洞，攀着松树枝也许能
    爬过去，我的轻功不行，我可是不敢，嘻嘻。\n");
	return 1;
}
