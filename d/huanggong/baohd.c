// Room: /d/huanggong/baohd.c

inherit ROOM;

void create()
{
        set("short", "���͵�");
        set("long", @LONG
�����������ĵط����Ǳ��͵��ˣ������ǻ��ϵ��Եĵط���
ÿ��������˶����������������һ���Լ���ѧʶ������������
��������̫���ˣ�������������İڷ����������ӣ���Ϊ����
֮�ã���˵û�и��ϵ��ǵ��Ե�ʱ��Ҳû�����׵ġ�

��������ǽ�Ϲ���һ������������֣�

	��ɽ֮�� �ڵ²�����

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"longzm",
  "south" : __DIR__"zhonghd",
  "north" : __DIR__"qianqg",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}