// Room: /d/hangzhou/zfjianlao.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǻ��ݸ��õļ��Σ����ﲻ����Ѻɱ��Խ���Ľ�����
�����ٱ��ص�С���ͽ�����˰������Ҳ�����������������
��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zfpath2",
]));

	setup();
	replace_program(ROOM);
}
