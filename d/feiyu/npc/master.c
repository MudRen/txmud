// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int kill_me(object me);
int ask_father(object me);
int ask_rainplate(object me);

void create()
{
	object ob;

        set_name("张雨懿", ({ "master zhang", "master","zhang" }) );
        set("long","别看张雨懿是一个二十岁的小丫头，但是她父母
教给她的一身功夫，却已经在江湖上罕有敌手。\n");
        set("title", RED"绯雨阁女主人"NOR);
        set("attitude", "heroism");
        set("gender","女性");

	set("class","rain");
	set("age",22);

        set("str", 35);
        set("cor", 40);
        set("per", 30);
        set("int",30);
	set("kar",50);

	set("max_kee",2500);
	set("max_gin",2000);
	set("max_sen",2000);

        set("max_force",8000);
        set("force",8000);
        set("force_factor",240);

	set("combat_exp", 6000000);
        set("inquiry", ([
	"leave" : (: call_other, __FILE__, "want_to_leave" :),
	"离开" : (: call_other, __FILE__, "want_to_leave" :),
	"叛师" : (: call_other, __FILE__, "want_to_leave" :),

                "四杀手": (: kill_me :),
                "父亲"	: (: ask_father :),
                "绯雨令": (: ask_rainplate :),
        ]) );

        set_temp("apply/damage",200);

        create_family("绯雨阁", 1, "女主人");
        set_skill("unarmed", 220);
        set_skill("sword",300);
        set_skill("force",280);
        set_skill("parry", 280);
        set_skill("dodge", 280);
        set_skill("literate",250);
        set_skill("jieqing-sword", 280);
        set_skill("suiyu-force", 250);
        set_skill("zuiyue-strike", 250);
        set_skill("feiyu-zhen", 250);
        set_skill("piaoyu-steps", 250);

        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");
        setup();

	ob = carry_object(__DIR__"obj/ziyansword");
        if(objectp(ob))
                ob->wield();

        carry_object(__DIR__"obj/shang")->wear();
}

void attempt_apprentice(object me)
{
	if(!me->query_temp("feiyu_upgrade_quest/passed"))
		return;

	else
	{
		me->delete_temp("feiyu_upgrade_quest");
		command("smile");
		command("say 好，今天我就收你为徒。。\n");
		command("recruit " + me->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	::recruit_apprentice(ob);
	ob->set("class","rain");
	return 1;
}

int kill_me(object me)
{
	if(me->query("class") != "rain")
		return 0;

	if(me->query("combat_exp") > 300000 )
	{
		command("?");
		command ("say 看来你知道的太多了，我已经不能留你的活口了。\n");
		this_object()->kill_ob(me);
		me->kill_ob(this_object());
		return 1;
	}

	command("?");
	command("say 你问那么多干嘛？");
	return 1;
}

int accept_object(object me, object ob)
{
	object obj;

	if(me->query("class") != "rain")
		return 0;

	if(ob->query("id") == "feiyu sword")
	{
		if(ob->query("master") != me->query("id"))
		{
			command("say 这把剑是假的！真没用！");
			return 1;
		}

		me->set_temp("feiyu_upgrade_quest/passed",1);

		say("张雨懿说道：没想到你居然找回了镇门之宝，你为本门立了大功了。\n");
		return 1;
	}

	if(ob->query("id") == "qingxia sword")
        {
                if (!me->query_temp("louth_kfather"))
			return 1;

                tell_object(me,"张雨懿道：你果然帮我杀了那个狗贼，我也
没有什么可以报答你的，拿上这块手绢，把
它交给我母亲，她会把〖绯雨惊鸿剑法〗传
给你的。\n");
		obj=new(__DIR__"obj/shoujuan"); 
		obj->move(me);
		ob->set("master",me->query("id"));
		return 1;
        }
        return 0;
}

int ask_father(object me)
{
        command ("heng");
        command ("say 不要提那个背信弃义的狗贼！如果你能帮我杀
了他，拿回他身上的青霞剑给我，我会重重报答你的。\n");
        me->set_temp("louth_kfather",1);
        return 1;
}

int ask_rainplate(object me)
{
	if(me->query("combat_exp") <= 1200000 )
	{
		command ("say 以你目前的能力，还不能领取绯雨令。\n");
		return 1;
	}

	command ("nod");
	command ("say 好！去敲门吧，如果你运气好的话，那个人就能给你绯雨令。\n");
	me->set_temp("louth_qupai",1);
	return 1;
}
