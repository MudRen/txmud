// Room: /d/path7/lu1.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ�������Ļ���������ض����û����̵���ʵ���Ժ���
����һ��ϸɰ���ǳ��������ٽ��۶���ȴ��������һ��������Զ
Զ�������������ǵĶ����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/changan/out_changan_e",
  "east" : __DIR__"lu2",
]));

	set("outdoors", "path7");

	setup();
	replace_program(ROOM);
}
