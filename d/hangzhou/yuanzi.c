// Room: /d/hangzhou/yuanzi.c

inherit ROOM;

void create()
{
	set("short", "�ƾɴ�Ժ");
	set("long", @LONG
���ﱾ���Ǻ�����Ա��ҵĵز�����Ϊʢ���ֹ��𽥵Ļ�
���ˣ���֪��ʲôʱ��ʼ��һЩ��ؤ��ʼ�̾������Ժ����
Χ�������˵Ķѷ���һЩ�������м���һ������裬�Ա߻���һ
��ˮ����
LONG
	);
	set("outdoors", "hangzhou");
	set("resource/water",1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"changane3",
]));

	setup();
	replace_program(ROOM);
}
