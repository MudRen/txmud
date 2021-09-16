// dizi7.c
// by dicky

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("踏雪秋蝉", ({ "taxue qiuchan", "qiuchan","girl"}));
	set("class","taxue");
	set("nickname", HIC"知晓天下"NOR);
        create_family("踏雪山庄", 2, "弟子");
        set("gender", "女性");
	set(NO_KILL,1);
        set("age", 20);
        set("attitude","friendly");
	set("long", "他是庄主踏雪靖远的独生女，她生得极为美貌,一双眼睛顾盼生辉。\n由于她从小聪明好学，又得名师指点，所以她几乎知晓天下所有的功夫！\n");

        set("str", 30);
        set("dex", 30);
        set("con", 30);
        set("int", 30);
        set("no_get",1);
        set("per", 30);
        set("max_kee", 4000);
        set("max_gin", 4000);
        set("force", 4000);
        set("max_force", 4000);
        set("max_atman", 4000);
        set("max_mana", 4000);

        setup();
        carry_object(__DIR__"obj/skirt")->wear();
        carry_object(__DIR__"obj/shoe")->wear();
}

void init()
{
        add_action("lingwu","ask");
}

int lingwu(string arg)
{
	int bl,sl,bonus;
        object me,ob,where;
        string special,name;

	ob = this_object();
	me=this_player();
	where = environment(me);

        if (!arg) return 0;
        if (!sscanf(arg, "%s about %s", name, arg)) return 0;
        if (!id(name)) return 0;

        write( "你向踏雪秋蝉请教关于「" + to_chinese(arg) + "」的疑问。\n");
        if (me->is_busy() || me->is_fighting()) {
                command("say 你正忙着呢。");
                return 1;
        }

        if (!(special=me->query_skill_mapped(arg))) {
                if (arg == to_chinese(arg))
                        command("say 「" + arg + "」是什么武功？怎么我没听说过？");
                else
                        command("say 我只能从你的特殊技能中给你指点。");
                return 1;
        }
        if (!me->query_skill(arg,1)) {
                command("say 你不会这种技能。");
                return 1;
        }

        if((int)me->query("potential", 1) < 1 ) 
                return notify_fail("你从实战中得到的潜能已经用完了。\n");

        bl=me->query_skill(arg,1);
        if (me->query("gin")*100/me->query("max_gin") < 50) {
                me->receive_damage("gin",bl/20);
                command("say " + RANK_D->query_respect(me) + "先休息一下吧。");
                return 1;
        }

        if (bl > 350) {
                command("say " + RANK_D->query_respect(me) + "的基本"+to_chinese(arg)+"已经够高了，我也不能指点你什么！");
                return 1;
        }

        sl=me->query_skill(special,1);
        if (bl > sl) {
                command("say " + RANK_D->query_respect(me) + "的"+to_chinese(special)+"造诣不够，我不能指点你更深一层的"+CHINESE_D->chinese(arg)+"。");
                return 1;
        }
        write("你听了" + name() + "的指点，对"+to_chinese(arg)+"的体会又深了一层。\n");
        me->receive_damage("gin",bl/20);
        me->add("potential", -random(2));
        bonus =((me->query("int") +me->query_skill("literate")/10)* 10 /3)+10;
        me->improve_skill(arg, bonus);
        return 1;
}