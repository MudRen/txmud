// Room: /wiz/louth/c/liangfendian.c

inherit ROOM;

void create()
{
	set("short", "���۵�");
	set("long", @LONG
����һ���ܴ�����۵꣬�˵��ڳɶ��Ѿ����ϰ������ʷ��
�������ĳɶ����������ۡ��������ۿ��Ƴɶ�һ�������۵�ζ��
�ã����ٽ��ˡ���˵�в��ٵĴ����ﶼ����������Ʒ�������أ�
���������߾�������·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wmlu3",
]));
        set("objects",([
        __DIR__"npc/huaboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
