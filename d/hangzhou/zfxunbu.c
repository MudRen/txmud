// Room: /d/hangzhou/zfxunbu.c

inherit ROOM;

void create()
{
	set("short", "Ѳ����");
	set("long", @LONG
�����Ǻ��ݸ��õ�Ѳ������ƽʱѲ��������Ѳ�ߣ���������
������������ǽ�Ϲ��˲����䵶������֮��ı�������һ����
ǽ���˼���ľ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zfpath1",
]));

	setup();
	replace_program(ROOM);
}
