// Room: /d/shaolin/yongdao2.c

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
�����������µ�һ����ʯ������������һ�����ͺ���
�˾Ͳ���ȥ�ˣ���Ϊ��Ժ�����ֵĲؾ��󡢷���¥���صء�����
�����Ϻ�������ʯ����������ͭ������ڣ��������޺�����
�ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yongdao1",
  "north" : __DIR__"yongdao3",
  "east" : __DIR__"luohan1",
  "west" : __DIR__"tongren1",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
