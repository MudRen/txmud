// Room: /u/w/wangs/b/kai28.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ��������˼ң�����լԺ�������˻��ݣ�������һ
������С¥�����߻��м���ƫ����һ������ģ��������Ů������
�������ˮ�۱�ϴˢ��Ʒ��������һ�£�ԭ����������˾��ǿ�
��Ƥ���е��ϰ塣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai27",
]));
        set("objects",([
        __DIR__"npc/shaofu": 1,
]));

	setup();
	replace_program(ROOM);
}
