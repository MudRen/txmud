// wulingzhi.c

inherit ITEM;

void create()
{
        set_name("����֬", ({ "wu ling zhi"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ������֬,����֬����ζ����,������Ѫȥ��,ͨ��
ֹʹ��\n");
        }
}
