// Room: /u/w/wangs/b/kai105.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǿ���ǵĹ����ˡ������ϵ������������ģ��쳣æ
µ�������﹤���Ĵ���ǿ�������ƶ���˼ҡ�Ҳ��һЩ�����
�����ˡ������Ƕ���һ����֮ͬ��������ƾ���ǵĺ�ˮ��������
���ͼ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kai103",
  "east" : __DIR__"kai107",
]));
        set("objects",([
        __DIR__"npc/gongtou":1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
