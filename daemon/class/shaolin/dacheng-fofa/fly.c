// fly.c

#include <ansi.h>
inherit F_NATURE;

string fname = "/d/shaolin/fayanvoid";
private void do_select(string num,object me,object *rooms);
private void arrive_dest(object me,object room);

int conjure(object me)
{
	mapping where;
	int time;
        object *inv,*rooms = ({});
	string out;

	if(!objectp(me) || !environment(me) || (me->query("class") != "shaolin"))
		return 0;

	if( me->query_skill("dacheng-fofa",1) < 100)
		return notify_fail("你的『大乘佛法』修为不足。无法施展『移行穿梭』。\n");

	if(me->is_fighting())
		return notify_fail("战斗中无法施展『移行穿梭』。\n");

	if(me->query("atman") < 500)
		return notify_fail("你的灵力不足。无法施展『移行穿梭』。\n");
        if(!environment(me)->query("outdoors"))
                return notify_fail("此地无法施展『移行穿梭』。\n");

        inv = filter_array(deep_inventory(me),
                (: $1->is_character() :));

        if(sizeof(inv))
                return notify_fail("你的佛法修为受到其他人的影响，无法施展『移行穿梭』。");


	if(!mapp(where = me->query("family/fofa")) || !sizeof(where))
		return notify_fail("你的『空明法眼』目前没有任何方向，无法施展『移行穿梭』。\n");

	time = time();

	foreach(string fname,int t in where)
	{
		object room;
		string f;

		if( (t - time) <= 0 )
		{
			me->delete("family/fofa/"+fname);
			continue;
		}

		f = replace_string(fname,"&","/");
		room = find_object(f);
		if(!room)
			room = load_object(f);
		if(!room)
		{
			me->delete("family/fofa/"+fname);
			continue;
		}
		else
			rooms += ({ room });
	}

	if(!sizeof(rooms))
		return notify_fail("你的『空明法眼』目前没有任何方向，无法施展『移行穿梭』。\n");

	if(sizeof(rooms) == 1)
	{
		do_select(sprintf("%d",1),me,rooms);
		return 1;
	}

	out = "你目前法眼所及的地方有：\n";
	for(int i=0;i<sizeof(rooms);i++)
		out += sprintf("%d. 【%s】\n",(i+1),rooms[i]->query("short"));

	tell_object(me,sprintf("%s\n请选择你要前往的地点(q 取消)：",out));
	input_to((: do_select :),me,rooms);
	return 1;
}

private void do_select(string num,object me,object *rooms)
{
	int n, day = query_day(0),ski,up;
	object obj;
	mapping t;

	if(!objectp(me) || (num[0] == 'q'))
		return;

	if(!sscanf(num,"%d",n))
	{
		tell_object(me,"选择错误。\n");
		return;
	}

	if( (n < 1) || (n > sizeof(rooms)) )
	{
		tell_object(me,"选择错误。\n");
		return;
	}

	ski = me->query_skill("dacheng-fofa",1);
	if(ski < 150)
		up = 10;
	else if(ski < 200)
		up = 20;
	else
		up = 30;

	if(!mapp(t = me->query("family/flytime")))
	{
		t = allocate_mapping(2);
		t["date"] = day;
		t["times"] = 0;
	}

	if( (t["date"] == day) && (t["times"] >= up) )
	{
		tell_object(me,sprintf("你今天已经太累了，再也没有精力施展『移行穿梭』了。\n"));
		return;
	}
	if(!t["date"] || (t["date"] != day))
	{
		t["date"] = day;
		t["times"] = 1;
	}
	else
		t["times"]++;

	me->set("family/flytime",t);

	n--;

	me->start_busy(10);

	tell_object(me,sprintf("\n双眼紧闭，双手合十，脑海里慢慢浮现出【%s】的景象，
你只觉的脚下一轻，已不知身在何处。。。\n\n",rooms[n]->query("short")) );

	tell_room(environment(me),sprintf(BWHT BLU"%s双眼紧闭，双手合十，你只觉得周围的空气开始急速旋转，
一道眩目的银光过后，%s从你眼前消失了。。。\n\n" NOR,me->name(),me->name()),({me}));

	me->add("atman", -500);
	me->move(fname,1);
	if(objectp(obj=me->query_temp("on_rided")))
		obj->move(fname);
	call_out((: arrive_dest :),5,me,rooms[n]);
}

private void arrive_dest(object me,object room)
{
	object obj;

	if(!objectp(me))
		return;

	tell_room(room,sprintf(BWHT BLU"\n突然，你只觉得周围的空气开始急速旋转。。。
一道眩目的银光过后，%s出现在你眼前。。。\n\n"NOR,me->name()));


	tell_object(me,sprintf("\n不知过了多长时间，你感觉周围的景物慢慢的发生了变化，
睁眼一看，你已经来到了【%s】。。。\n\n",room->query("short")));

	me->move(room);
	if(objectp(obj=me->query_temp("on_rided")))
		obj->move(room);

	if(me->query("gin") > 20)
		me->set("gin",20);
	if(me->query("kee") > 20)
		me->set("kee",20);
	if(me->query("sen") > 20)
		me->set("sen",20);

	me->stop_busy();
}
