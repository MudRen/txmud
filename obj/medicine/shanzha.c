//shanzha.c

inherit ITEM;

void create()
{
        set_name("ɽ�", ({ "shan zha"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ��ɽ�,ɽ髵���ζ�����,�����������٣��������͡�\n");
        }
}