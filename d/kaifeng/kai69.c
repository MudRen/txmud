// Room: /u/w/wangs/b/kai69.c

inherit ROOM;

void create()
{
	set("short", "����鱦��");
	set("long", @LONG
����鱦�в����ǿ��⸮�����鱦�У�Ҳ��ȫ����������
�鱦��֮һ�������������������ʵ����������֮һ������ȫ
��������ж������⣬�����µĲ�ҵ�������鱦�У�����Ǯׯ��
ҩ�ꡢ�ĳ�����Ժ�ȵȣ�ֻҪ��׬Ǯ�����ⶼ������һ�ݣ���ˣ�
����ǵ������������Ծ��Եķ��ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai68",
]));
        set("objects",([
        __DIR__"npc/liboss": 1,
]));

	setup();
	replace_program(ROOM);
}
