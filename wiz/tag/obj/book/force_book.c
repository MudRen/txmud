/*
/obj/book/ 
*/

inherit ITEM;

void create()
{
        set_name("���ڹ����š�", ({ "force book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("long",
"����һ�������ڹ��ķ����飬������ǳ��\n"
        );
        set("value", 3000);
        set("material", "paper");
        set("skill", ([
        "name" :          "force",      // �书����.
        "exp_required" :  1000,         // ��������Ҫ����;���.
        "sen_cost" :      1,            // ���黨����.
        "difficulty" :    22,           // �ο� /cmds/std/study.c
        "max_skill" :     50,           // �ܶ�������ߵȼ�.
]) );
        }
}
