// yedie.c

#include <ansi.h>
inherit NPC;

//string ask_me(object me);

void create()
{
        set_name("夜蝶", ({ "ye die" , "die"}) );
        set("gender", "女性" );
        set("age",18 );
        set("nickname",HIC"雪之舞  雨中赋"NOR);
        set("long", "她是天雪与地雨的结晶 拥有万物的精灵,仿佛似冰雪
剔透,深蓝的眼眸好似夜间的大海闪烁着点点星光,天
地间万物为之倾倒。\n");
        set("title",HIW"绯雨阁冰之精灵--雪虞轩紫"NOR);
        set("combat_exp", 100);
        set("per", 30);

        set("chat_chance", 5);
        set("chat_msg", ({
                "夜蝶幽幽的唱道：花雨飘零笑红尘，嫣然一笑戏九天。。。\n",
                "夜蝶伤心的哭了出来。。。。\n",
                "夜蝶叹道：魔非魔 道非道 善恶在人心 欲非欲 情非情 姻缘由天定。\n",
        }) );
        set("inquiry", ([
	"情" : "问世间情为何物。。。。。。\n", 
        //"戒指" : (: ask_me :),
]) );

	setup();
	carry_object(__DIR__"obj/nishang")->wear();
}

int accept_object(object me, object ob)
{
	if(me->query("class") != "rain")
		return 0;

	if(ob->query("id") == "flower ball")
	{
		if(me->query("mark/louth_huaqiu"))
		{
			tell_object(me,"夜蝶说道：多谢啦，上次就是你把这个花球带给我的。\n");
			return 1;
		}

		command("say 太好了,这个花球是我老公做的!!");
		command("say 我怎么感谢你呢？？\n");
		command("think");
		call_out("thanks",8,me);
		return 1;
	}

	switch(ob->query("id"))
	{
		case "red flower":
			call_out("greeting",6,me,1);
			break;
		case "yellow flower":
			call_out("greeting",6,me,2);
			break;
		case "blue flower":
			call_out("greeting",6,me,3);
			break;
		case "purple flower":
			call_out("greeting",6,me,4);
			break;
		case "white flower":
			call_out("greeting",6,me,5);
			break;
		default:
			return 0;
	}

	return 1;
}

void greeting(object me,int n)
{
	if(!objectp(me) || (environment(me) != environment()))
		return;

	switch (n)
	{
		case 1:
			tell_object(me,"夜蝶小声地说：告诉你一个秘密，据说绯雨阁有一把宝剑掉
在了戒情崖下边，一直没有人找到过。\n");
			break;;
		case 2:
			tell_object(me,"夜蝶小声地说：再告诉你一个秘密，据说要是谁给环儿吹一曲
『清懿幽』，那个人就能从环儿那里学到很多知识。\n");
			break;
		case 3:
			tell_object(me,"夜蝶小声地说：再告诉你一个秘密，据说在梅花阁里有一位谁也
没见过的人，那个人一直呆在屏风后边，有一次我偷偷听见了那个人说什么“暗杀”什么东西。。\n");
			break;
		case 4:
			tell_object(me,"夜蝶小声地说：再告诉你一个秘密，据说绯雨阁里前段时间有个弟
子跟张雨懿要着了绯雨令，那可是张雨懿第一次发给弟子绯雨令呀！\n");
			break;
		case 5:
			tell_object(me,"夜蝶小声地说：最后再告诉你一个秘密，据说绯雨阁里有间屋子能
听见海哭的声音。\n");
			break;
	}
}

void thanks(object me)
{
	if(!objectp(me) || (environment(me) != environment()))
		return;

	message_vision("夜蝶把右手轻轻放在$N的头顶。。。\n",this_player());
	message_vision("$N只觉得一股热浪从夜蝶手心传来。。。\n",this_player());
	command ("say 好了，你的功力已经提高了。\n");
	me->add("max_force",200);
	me->set("mark/louth_huaqiu",1);
}
