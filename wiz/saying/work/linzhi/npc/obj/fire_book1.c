//fire_book1.c ���浶���߼��鼮��
inherit ITEM;
inherit F_CONTROL;

void create()
{
        set_name("�����浶����", ({ "advanced fire-blade book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("long","���浶�����׵�����\n");
        set("NO_SELL",1);
        set("NO_DROP",1);
        set("NO_GET",1);
        set("material", "paper");
        set("skill", ([
        "name" :          "fire-blade",        // �书����.
        "exp_required" :  1000000,         // ��������Ҫ����;���.
        "skill_required" :  70,         // ��������Ҫ����;���.
        "sen_cost" :      40,            // ���黨����.
        "difficulty" :    52,           // �ο� /cmds/std/study.c
        "min_skill" :     70, 
        "max_skill" :     200,           // �ܶ�������ߵȼ�.
]) );
        }
}
