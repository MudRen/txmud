#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("孙醉芳", ({ "sun zuifang", "sun","zuifang" }) );
        set("long","孙醉芳是绯雨阁的开山祖师，因为她的丈夫
弃她而去，所以黯然退出江湖。\n");
        set("title", RED"绯雨阁开杀祖师"NOR);
        set("attitude", "heroism");
        set("gender","女性");
        set("str", 30);
        set("age",52);
        set("per", 30);
        set("int",9);
        set("max_force",6000);
        set("force",6000);
        set("force_factor",210);
        set("score",100);
        set("combat_exp", 4000000);
        set_temp("apply/damage",100);


        create_family("绯雨阁", 0, "开山祖师");
        set_skill("unarmed", 200);
        set_skill("sword",280);
        set_skill("force",260);
        set_skill("parry", 280);
        set_skill("dodge", 260);
        set_skill("literate",100);
        set_skill("jieqing-sword", 280);
        set_skill("suiyu-force", 250);
        set_skill("zuiyue-strike", 250);
        set_skill("piaoyu-steps", 250);

        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");


        setup();

        carry_object(__DIR__"obj/yfcloth")->wear();
        carry_object(__DIR__"obj/qiankousword")->wield();
}

int accept_object(object me, object ob)
{
        object obj;
        if(ob->query("id") == "xiao shoujuan")
        {
                me->set("mark/louth_learnsword", 1);
                command ("nod");
                say("孙醉芳说道：嗯。看来你已经帮我们娘俩杀了那个
狗贼，今天我就传你〖绯雨惊鸿剑法〗！\n");
                return 1;
        }
        return 0;
}
int recognize_apprentice(object ob)
{
        if (this_player()->query("mark/louth_learnsword")==1)
        return 1;
        else return 0;
}

