#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"�����ɾ���"NOR, ({ "xian book's copy"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("long",
"ԭ���ഫ���ɵõ�����������������¼���ڶ�������\n"
"��֮����������Ҫ�����������޵����ɵ�����˵����\n"
"���޼�֮������������ԭ�־���ֳ�����\n");
        set("value", 200000);
        set("material", "paper");
        set("skill", ([
        "name":         "magic",    // �书����.
        "exp_required": 1000000,         // ��������Ҫ����;���.
        "sen_cost":     1,             // ���黨����.
        "gin_cost":     1,             // ���黨�ľ�.
        "difficulty":   26,            // �ο� /cmds/std/study.c
        "min_skill":    151,
        "max_skill":    200,           // �ܶ�������ߵȼ�.
]) );
        }
}
