// master1.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me(object me);

void create()
{
        set_name("于凝霜", ({ "master yu", "master","yu" }) );
        set("long","于凝霜是张雨懿的师姐。\n");
        set("title", HIM"绯雨阁首席大弟子"NOR);
        set("attitude", "peaceful");
        set("age", 31);
	set("class","rain");
        set("gender", "女性");
        set("per", 30);
	set("str", 50);
	set("kar", 35);
        set("int",30);
        set("max_force",4000);
        set("force",4000);
        set("force_factor",200);
        set("combat_exp", 3000000);
	set("max_kee",2000);
	set("max_gin",2000);
	set("max_sen",2000);

        create_family("绯雨阁", 2, "女主人");

        set("inquiry", ([
	"leave" : (: call_other, __FILE__, "want_to_leave" :),
	"离开" : (: call_other, __FILE__, "want_to_leave" :),
	"叛师" : (: call_other, __FILE__, "want_to_leave" :),

        "绯雨短剑" : (: ask_me :),
]) );

        set_skill("unarmed", 200);
        set_skill("sword",200);
        set_skill("force",200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate",200);
        set_skill("jieqing-sword", 200);
        set_skill("suiyu-force", 200);
        set_skill("zuiyue-strike", 200);
        set_skill("feiyu-zhen", 150);
        set_skill("piaoyu-steps", 200);
 
        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");
        setup();

        carry_object(__DIR__"obj/bingxue")->wear();
        carry_object(__DIR__"obj/ziqingsword")->wield();
}

void attempt_apprentice(object me)
{
        if( me->query("title") != "普通百姓" || me->query("gender")!="女性" )
        {
		command("say 『绯雨阁』向来只收女弟子。");
		return;
        }

	if( (me->query("per") < 25) || (me->query("age") >= 30) )
	{
		command("say 『绯雨阁』向来只收年轻漂亮的女孩子，你还是走吧。");
		return;
	}

	else
	{
		command("xixi");
		command("say 很好，既然我们有缘，以后多多跟我学吧。\n");
		command("recruit " + me->query("id") );
	}
}

int recruit_apprentice(object me)
{
	::recruit_apprentice(me);
	me->set("class", "rain");
        return 1;
}

string ask_me(object me)
{
	if(me->query("class") != "rain" || me->query("gender") != "女性")
		return "你问这干什么？\n";

	if(me->query("combat_exp") < 1800000)
		return "你的江湖经历还太浅，再磨练磨练吧。\n";

	if(me->query_skill("sword") < 200)
		return "你对剑法还欠火候，这件事情十分危险难办，你还是先把武功练好吧。\n";

	if(me->query_temp("feiyu_upgrade_quest/ask_my"))
		return "我知道的都告诉你了，你自己去想办法吧。\n";

        me->set_temp("feiyu_upgrade_quest/ask_my",1);
            
	return "那都是二十年前的旧事了，当时我岁数也很小，只有有一些
            印象。那时师傅倾心于一个叫“刘浪”的男子，那人长得很
            英俊武功也很好。可是就在少主人即将临盆大家都欢喜忙碌
            的时候，刘浪却趁人不备盗走了师祖传下的门主信物，绯雨
            阁镇门之宝--菲鱼短剑，当时师傅无力追赶，只能托朋友拦
            截，却还是让他跑了，从此再无音讯。师傅因此也愤然出走。
            本门上下不断四处打听刘浪的消息，不论怎样也要报此深仇
            大恨，夺回绯雨短剑！你既有此志向为是自然不会阻拦与你，
            听说奉天府的吴猎户知道一些情况，你可以去了解一下。不
            过此事非常凶险，你要多家小心。\n";
}
