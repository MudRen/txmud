// Room: /d/huanggong/daolu6.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
�����ڳ����Ĺ����У�������Ǭ�幬�������Ǿ�Զ�ţ�����
���ߵ���, �������ɵĳ��Ƽ��Ϲ���һ�������Ĺ���! ��ҹ֮��
�ƻ�Ի�! ʮ������������ȥ��һ����ɽ������������ʾ����
��԰�ֵĵ��š�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"tj_room",
  "west" : __DIR__"qianqg",
  "east" : __DIR__"jingym",
]));
	set("outdoors", "huanggong");

	setup();
	replace_program(ROOM);
}
