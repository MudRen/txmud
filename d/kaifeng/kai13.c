// Room: /u/w/wangs/b/kai13.c

inherit ROOM;

void create()
{
	set("short", "���к���");
	set("long", @LONG
���������е�С���ϣ�����������ˮ֮�����Ƕ���������
���㣬ϸ�����֦��΢�紵������������ϣ�����С�������
ˮ֮�е�������׷����Ϸ���㲻�ɵ��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"kai14",
  "southwest" : __DIR__"kai12",
]));
        set("objects",([
        __DIR__"npc/xianren": 1,
]));
        set("resource/water",1);

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
