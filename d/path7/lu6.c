// Room: /d/path7/lu6.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ�������Ļ���������ض����û����̵���ʵ���Ժ���
����һ��ϸɰ���ǳ��������ٽ��۶���ȴ��������һ��������һ
ֱ�߾��ܵ������ǵĶ����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"lu7",
  "northeast" : "/d/renyi/renyi6",
  "west" : __DIR__"lu5",
]));

	set("outdoors", "path7");

	setup();
	replace_program(ROOM);
}
