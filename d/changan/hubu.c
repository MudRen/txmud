// Room: /d/changan/hubu.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǻ������š��׻�˵�����ǳ�͢��Ǯ���ӣ����Ի���
���ù����������ɻ����ؼ���������صĹ�Ա��ְ��������ǰ��
����һ���Ҷ����顰�����������ĸ����֡�һЩ�����Ǹ�������
��С����Ҳ������ܣ���������ùٴ���һ�¡������������顣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ehroad3",
]));

	set(SAFE_ENV,1);

	set("objects",([
        NPC_DIR"sima" : 1,
]));
	setup();
	replace_program(ROOM);
}
