#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"�����ɾ���"NOR, ({ "xian book"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("long", @LONG
���־������ɵõ�����������������¼���ڶ���������֮
���������޼�֮������������������ʿ�ķ���������Ϊ��
�õ���ôһ������ѡ�
LONG
        );
        set("value", 500000);
        set("material", "paper");
        set("skill", ([
        "name":         "magic",    // �书����.
        "exp_required": 2000000,         // ��������Ҫ����;���.
        "sen_cost":     1,             // ���黨����.
        "gin_cost":     1,             // ���黨�ľ�.
        "difficulty":   26,            // �ο� /cmds/std/study.c
        "min_skill":    101,
        "max_skill":    300,           // �ܶ�������ߵȼ�.
]) );
        }
}
