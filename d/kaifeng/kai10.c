// Room: /u/w/wangs/b/kai10.c

inherit ROOM;

void create()
{
	set("short", "��ͤ");
	set("long", @LONG
�����ڴˣ��羰���������к��Ͼ����۵ס�������ȥ������
���������к���͵ع��˼�������ʧ���غζ����ĸ߽����֮�У�
���̵ĺ�ˮ�ϼ�Ҷ�������еص���һ����������������б����
���������һƬ���ҵĲ�����������ƽ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai16",
]));

        set("objects",([
        __DIR__"npc/xianren" : 1,
]));

	setup();
	replace_program(ROOM);
}
