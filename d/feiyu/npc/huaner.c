// huaner.c

#include <ansi.h>

inherit NPC;

int query_is_feiyu_huaner() { return 1; }

int ask_pu(object me);

void create()
{
        set_name("环儿", ({ "huan er"}) );
        set("title",WHT"无情忘忧人"NOR);
        set("gender", "女性" );
        set("age", 22);
        set("long", "她有一头及肩的秀发,被风吹的颇有一些凌乱。
白色的纱褛，曳地的长裙。
头发下，是张年轻、姣好，而生气蓬勃的脸。
皮肤白，眼珠乌亮，
她的笑容温暖如春，眼波明媚如水！
");
        set("combat_exp", 500);
        set("per", 30);
        set_skill("literate",360);
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
                "环儿自言自语道：谁能再给我吹一曲『清懿幽』呀？\n",
        }) );   

        set("inquiry", ([
                "绯雨阁秘道" : "据说秘道里全是机关，而且进去了就迷路。\n", 
                "秘道入口" : "好象听别人说是在一间小屋里。\n", 
                "地下秘室" : "地下秘室里藏着我们绯雨阁的武功秘籍。\n",
                "学习" : "如果你能给我吹一曲 『清懿幽』的话，我就答应指点指点你 。\n",
                "指点" : "如果你能给我吹一曲 『清懿幽』的话，我就答应指点指点你 。\n",
                "问题" : "如果你能给我吹一曲 『清懿幽』的话，我就答应指点指点你 。\n",
                "秘道" : "据说秘道里全是机关，而且进去了就迷路。\n", 
                "清懿幽箫谱" : (: ask_pu :),
                "箫谱" : (: ask_pu :),
                "白玉箫" : "那是一根纯玉做的箫，只有用那根玉箫，才能吹得了『清懿幽』这首曲子。\n",
                "镇山之宝" : "听说好象是一把百年罕见的宝剑，剑鞘上镶着很多宝石哦。\n",
]) );
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int recognize_apprentice(object ob)
{
	if(ob->query("mark/louth_huaner")
	&& (ob->query("class") == "rain"))
		return 1;
	else
		return 0;
}

int ask_pu(object me)
{
	if(me->query("mark/louth_huaner"))
	{
		command("say 谢谢你给我吹『清懿幽』这首曲子听。\n");
		return 1;
	}

	command ("think");
	call_out("think",5,me);
	return 1;
}

void think(object me)
{
	if(!objectp(me) || (environment(me) != environment()))
		return;

	tell_object(me,CYN"
环儿说道： 既然你真的想满足我这个小小的愿望，那就多谢啦！
那本『清懿幽』箫谱在我舅舅那里呢。听说吹奏『清懿幽』必须
要白玉箫才行。\n"NOR);
	me->set_temp("mark/huaner_pu",1);
}

void start_call()
{ call_out("do_refresh",2); }

void do_refresh()
{
	object *obs;
	int n;

	obs = all_inventory(this_object());
	if(!n = sizeof(obs))
		return;

	for(int i=0;i<n;i++)
	{
		if(obs[i]->query("equipped"))
			continue;
		else
			destruct(obs[i]);
	}
}
