#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"��Ѧ���ļ���"NOR+"�ϲ�", ({ "xue's 1st book"}));
        set_weight(150);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("long",
"Ѧ��ѧʿ���������ļ������Ƕ��������������õ���\n"
"���顣���ڷ��е��٣������²��ֶ౻��٣�����ʹ\n"
"��һ���������ļ����ӱ���\n");
        set("value", 20000);
        set("material", "paper");
        set("skill", ([
        "name":         "literate",    // �书����.
        "exp_required": 50000,         // ��������Ҫ����;���.
        "sen_cost":     1,             // ���黨����.
        "gin_cost":     1,             // ���黨�ľ�.
        "difficulty":   20,            // �ο� /cmds/std/study.c
        "min_skill":    51,
        "max_skill":    100,           // �ܶ�������ߵȼ�.
]) );
        }
}
