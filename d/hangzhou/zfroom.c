// Room: /d/hangzhou/zfroom.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��СС�ľ��ң�֪���ͷ�����ʱ��������Ӵ������
�ѣ��ݽǰ�����յ��������ƣ��м����һ�ź�ľ��Բ������ǽ
�Ϲ���һ�����ŵ�ˮī���ӡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"zfpath5",
  "east" : __DIR__"zfpath7",
  "north" : __DIR__"zfxiaojie",
]));

	setup();
	replace_program(ROOM);
}
