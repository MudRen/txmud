// jinyinhua.c

inherit ITEM;

void create()
{
        set_name("������", ({ "jin yin hua"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�Ľ�����,����������ζ�ʺ�,�������Ƚⶾ��\n");
        }
}
