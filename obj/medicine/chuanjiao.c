//chuanjiao.c

inherit ITEM;

void create()
{
        set_name("����", ({ "chan jiao"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�Ĵ���,��������ζ�����ж�,��������ֹʹ��ɱ�档\n");
        }
}
