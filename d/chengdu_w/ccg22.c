// Room: /d/path5/ccg22.c

inherit ROOM;

void create()
{
	set("short", "ŭ��������");
	set("long", @LONG
������ŭ���������ߣ���ˮ�������ˮ��Ҳ���㼱������
�����Կ���ӵ׵�ʯͷ���ζ����㡣��ˮʮ���峺���㲻�����
Щˮ���ȣ������Ա����á����ﲽ�оͿ����ʹ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ccg23",
  "east" : __DIR__"ccg21",
]));
        set("outdoors", "chengdu_w");
	set("resource/water", 1);
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
