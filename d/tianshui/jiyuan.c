// Room: /u/xiaozhen/jiyuan.c

inherit ROOM;

void create()
{
	set("short", "����԰");
	set("long", @LONG
�����Ƿ�Բ����Ψһ��һ�Ҽ�Ժ�����ﵽ���ŵƽ�ʣ�����
�˱ǣ���λ��欵Ĺ��������Աߣ���ʱ�ĳ�����Ц��������Ȼû
���Ϸ����ޣ���������֬Ҳ���з��ϣ�¥�ϲ�ʱ�ش����������
���ε��������ſ�����һ������(pai)��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"jiyuan2",
  "east" : __DIR__"nroad1",
]));
	set("no_clean_up", 0);
	set("item_desc",([
	"pai" : "
ÿ�����Ӫҵ��

��ͨ����(putong)   ��������
��Χ����(yinwei)   ʮ������
��Χ����(jinwei) ��ʮ������

�����԰�(order)���ֻ���\n\n"
]));
	set("objects",([
	__DIR__"npc/m_boss" : 1,
]));

	set(SAFE_ENV,1);
	setup();
}

int valid_leave(object ob,string dir)
{
	string day_night;
	int time;

        if ( sscanf( NATURE_D->day_or_night(),"%s %d",day_night,time) )
        {
		if(day_night == "day" && dir == "up")
			return notify_fail("����������Ϣ�أ�����������������ɡ�\n");
	}
	return ::valid_leave(ob,dir);
}