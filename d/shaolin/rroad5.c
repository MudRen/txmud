// Room: /d/shaolin/rroad5.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������µĺ�Ժ�����������кô�һƬˮ�أ���Ϊ����
�������治�ٺܴ���㡣ˮ����Ʈ���˸�Ƽ����ˮ���ƣ���Ȼ��
�������¡��������������䳡�������ǹ����������ǰ��µ
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"rroad4",
  "east" : __DIR__"baiyi",
  "west" : __DIR__"yanwu",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
