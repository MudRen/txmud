//longgu.c

inherit ITEM;

void create()
{
        set_name("����", ({ "long gu"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�����ǣ����ǵ���ζ��ɬƽ��������������ƽ��Ǳ����\n");
        }
}
