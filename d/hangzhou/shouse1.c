// Room: /d/hangzhou/shouse1.c

inherit ROOM;

void create()
{
	set("short", "é��");
	set("long", @LONG
����һ����é�ݴ�ɵ�С�ݡ�����������ֻ��һЩ�Ҳ�
�ѷ����ݽǡ�����Ļ𻹵�ȼ���ţ��������˲��ò��뿪������
�����˿���ʲôҲû���ҵ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"spath4",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
