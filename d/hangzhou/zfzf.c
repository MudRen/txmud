// Room: /d/hangzhou/zfzf.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
�����Ǻ���֪�������ճ�����ĵط������м���һ��̴ľ��
��������ڵ�ȴ��һ�Ѿƺ�����ǽ�ĵط���һ������ܣ������
���˸����鼮���߽�ȴ�������渲���˺��ĳ����������þ�û
���������ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zfpath7",
]));

	setup();
	replace_program(ROOM);
}
