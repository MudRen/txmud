// baiguo.c

inherit ITEM;

void create()
{
        set_name("�׹�", ({ "bai guo"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�İ׹�,�׹�����ζ�ʿ�ɬƽ,������β��飬��̵������\n");
        }
}
