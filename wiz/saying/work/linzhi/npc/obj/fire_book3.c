//fire_book1.c ���浶���߼��鼮��
inherit ITEM;

void create()
{
        set_name("�����浶����", ({ "fire-blade book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("long","���浶������������\n");
        set("NO_SELL",1);
        set("material", "paper");
        set("skill", ([
        "name" :          "fire-blade",        // �书����.
        "exp_required" :  200000,         // ��������Ҫ����;���.
        "difficulty" :    52,           // �ο� /cmds/std/study.c
        "max_skill" :     70,           // �ܶ�������ߵȼ�.
]) );
        }
}
