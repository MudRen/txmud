// Room: /wiz/louth/c/baozipu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǳɶ�����İ����̡�����İ��ӿ�ν��͸�˴��ϱ���
�����ӡ����۰��Ӳ���ζ���ɿڣ�������ۺ�ɫ�󶼿���˵����
�����ƾ�Ʒ�����ٵĴ�ٹ���ÿ�궼Ҫ���ɶ��İ����̳�һ����
�����ѵ�һʳ�����ư������ž�������·�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wmlu3",
]));
        set("objects",([
        __DIR__"npc/dengboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
