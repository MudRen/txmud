#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"��Ѧ���ļ���"NOR+"�²�", ({ "xue's 3rd book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("long",
"Ѧ��ѧʿ���������ļ������Ƕ��������������õ���\n"
"���顣���ڷ��е��٣������²��ֶ౻��٣�����ʹ\n"
"��һ���������ļ����ӱ���\n");
        set("value", 50000);
        set("material", "paper");
        set("skill", ([
        "name":         "literate",    // �书����.
        "exp_required": 50000,         // ��������Ҫ����;���.
        "sen_cost":     1,             // ���黨����.
        "gin_cost":     1,             // ���黨�ľ�.
        "difficulty":   24,            // �ο� /cmds/std/study.c
        "min_skill":    201,
        "max_skill":    250,           // �ܶ�������ߵȼ�.
]) );
        }
}
