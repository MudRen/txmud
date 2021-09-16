// master1.c
// by dicky

#include <ansi.h>
inherit F_MASTER;
inherit NPC;

string ask_yujian();
string ask_chugu();

void create()
{
        set_name("踏雪容博", ({ "taxue rongbo", "rongbo"}) );
        set("class","taxue");
        create_family("踏雪山庄", 1, "弟子");

        set("title",HIW"残剑飞雪"NOR);	
        set("long", 
                "他是踏雪山庄的前辈祖师，号称“残剑飞雪”。\n"
                "他满头长发，直垂至地，长眉长须，鼻子嘴巴都被遮掩住了。\n"
                "他须发苍然，并未全白，只是不知有多少年不剃，就如野人一般毛茸茸地甚是吓人。\n");
        set("gender", "男性" );
        set("age", 60);
        set("attitude", "peaceful");
        set("str",40);
        set("int",30);
        set("con",30);
        set("dex",30);
        set("per", 25);
        
        set("max_kee", 9999);
        set("max_gin", 9999);
        set("max_force", 9999);
        set("max_atman", 9999);
        set("max_sen", 9999);
        set("max_mana", 9999);
        set("force_factor", 500);
        set("combat_exp", 30000000);

        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("unarmed", 300);
        set_skill("parry", 300);
        set_skill("sword", 300);
        set_skill("literate", 300);
        set_skill("xueli-steps", 300);
        set_skill("taxue-force", 300);
        set_skill("fenghui-sword", 300);
        set_skill("chuanyun-zhang", 300);

        map_skill("sword", "fenghui-sword");
        map_skill("parry", "fenghui-sword");
        map_skill("unarmed", "chuanyun-zhang");
        map_skill("dodge", "xueli-steps");
        map_skill("force", "taxue-force");

        set("inquiry", ([
                "出谷": (: ask_chugu :),
                "chugu": (: ask_chugu :),
                "驭剑术": (: ask_yujian :),
                "yujian": (: ask_yujian :),
                "name": "叫我残剑飞雪就好了。",
                "here": "这里是踏雪山庄。这里的秘密多如牛毛，看你能不能找全了。",
                "踏雪容博": "找我有什么事吗？",
                "残剑飞雪": "我就是啊，找我有什么事吗？",
                "踏雪山庄": "这里就是踏雪山庄。踏雪无痕那个小坏蛋在这里加了无数的ｑｕｅｓｔ，看你能不能找全了。",
        ]));

        setup();

        carry_object(ARMOR_DIR"cloth")->wear();
        carry_object(__DIR__"obj/zhujian")->wield();
}

void attempt_apprentice(object ob)
{
	if(ob->query("class") != "taxue")
		return;

	if(ob->query_skill("taxue-force",1) < 300)
	{
		command("say 你的踏雪神功火候不够，回去练练再说吧。");
		return;
        }

	if(ob->query_skill("force",1) < 300)
	{
		command("say 你的基本内功火候不够，回去练练再说吧。");
		return;
        }

	if(ob->query_skill("fenghui-sword",1) < 300)
	{
		command("say 你的风回雪舞剑学得火候不够，回去练练再说吧。");
		return;
        }

	command("smile");
	command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必有所成。\n");
	command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "taxue");
	ob->set("title",HIW"残剑飞雪衣钵传人"NOR);
        return 1;
}

string ask_yujian()
{
        object ob;
        ob = this_player();

        if(ob->query("class")!="taxue")
        return "我告诉你吧，这位"+ob->name()+"，驭剑术可是一门上乘的剑术哦！";

	if(ob->query("family/master_id") != "taxue rongbo")
        return "你觉得驭剑术深奥之极，凭自己的战斗经验一时间难以领会。";

        if(ob->query("taxue/yujian_pass"))
        return "你不是学会了驭剑术么，回去再加强练习吧！";

	ob->set("taxue/yujian_pass",1);
        command("smile");
	command("say 既然你这么用功，那我就教你怎么使用驭剑术吧！");
	message_vision (HIG"\n\n踏雪容博在$N的耳边低声说了几句，$N用心的听着踏雪容博的指导，体会驭剑术的精髓所在。\n\n"NOR, ob);
	return HIR"恭喜你，你终于学会了驭剑术！"NOR;
}

string ask_chugu()
{
        object ob;
        ob = this_player();

        if(ob->query("class")!="taxue")
        return "哈哈……，你是怎么来的就怎么回去吧，就不用麻烦老夫了！";

        if(!ob->query("taxue/yujian_pass"))
        return "没有学会驭剑术就想回去？你还是等学会了再走，免得出去丢人现眼！";
	message_vision(HIC"\n\n突然$N被踏雪容博用力甩了出去，但是$N感觉有股巨大的力量托着$P，\n$N忙运用内功，借助这股力量，采用驭剑术，轻轻向山崖飞了过去。\n\n"NOR,ob);
	ob->start_busy(2);
	ob->move("/d/taxue/shanya-s");
	tell_room(environment(ob), ob->name() + "突然从山谷下面飞了上来。\n", ({ ob }));
	return "那老夫就送你一程好了！";
}