// jindi_guard.c

#include <ansi.h>

inherit NPC;

string ask_enter(object who);

void create()
{
        set_name(HIW"��ɽ�ߴ�����"NOR, ({ "huashan guard", "guard", "dizi" }) );
        set("long",@LONG
����һλ������ɽ���صĻ�ɽ���ӣ���
��ͦ�Σ����㲻�ҽӽ���
LONG
);

        set("attitude", "peaceful");
 
        set("str", 50);
        set("cor", 40);
        set("con", 40);
        set("max_kee",3000);
        set("max_gin",3000);
        set("max_sen",3000);
        set("max_force",3000);
        set("force",3000);
        set("force_factor",50);

        set("combat_exp", 1000000);

        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force", 220);
        set_skill("zixia-force", 200);
        set_skill("huashan-sword", 180);
        set_skill("lingyun-steps", 180);
        set_skill("fuyunshou", 200);

        map_skill("unarmed", "fuyunshou");
        map_skill("sword", "huashan-sword");
        map_skill("force", "zixia-force");
        map_skill("dodge", "lingyun-steps");
 
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 40);

        set("inquiry", ([
                "����" : "��������֮�⣬�κλ�ɽ���Ӷ������������أ�",
                "Ѳ��" : (: ask_enter :),
                "check" : (: ask_enter :),
]) );

        setup();

        carry_object(ARMOR_DIR"cloth")->wear();
        carry_object(WEAPON_DIR"sword")->wield();
}

string ask_enter(object who)
{
        if(who->query("class") != "huashan")
                return "�㲻�ǻ�ɽ���ӣ��������ʲô����";

        if(who->query_temp("asked_yan_about_secret") ||
          who->query_temp("asked_ketou") )
                return "��û�еõ���������˽�Խ�����أ�";

        if( (who->query("combat_exp") < 1000000) )
                return "��Ҳ��Ѳ�飿���������ȣ��Ͻ���ȥ�����ɣ�";

        if(who->query_temp("asked_enter_again"))
                {
                who->delete_temp("asked_enter_again");
                return "���Ǻ���˵���������ڿ��Խ�ȥѲ�飡";
                }

        if(who->query_temp("asked_jindi_enter"))
                {
                who->set_temp("asked_enter_again",1);
                return RANK_D->query_respect(who) + "���Խ�ȥ�ˡ�";
                }

        who->set_temp("asked_jindi_enter",1);
           
        return "��λ" + RANK_D->query_respect(who) + "���ǹ���Ƿ����ѹִ�ʦ���ܷ���������Ѳ�顣\n" + RANK_D->query_respect(who) + "�����ڿ��Խ�ȥ�ˣ�һ��С�ģ�";
}

