// weapony.c  ����������

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "����������");
        set("long", @LONG
�����ǳ���������һ�������꣬һ���ſ��Կ������߳���
������ʽ�����������������ѡ����ֵ������������ſڵĵ�
����һ���������ͳɵĴ�����(sign)���ϱ����ϴ�֡�
LONG
        );
        set("exits", ([
                "south"           : __DIR__"nroad1",
]) );

	set("objects", ([
		__DIR__"npc/weaponboss" : 1,
]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д�������ȳ����� ����������
          ����ר����ʽ����������ʱ��ˡ�\n";
}
