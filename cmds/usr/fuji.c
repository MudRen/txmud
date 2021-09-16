// fuji.c

// 伏击. By Find. (11/28/98)

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string *valid_domain;
	object who,env;
	mapping ey;

	valid_domain = ({
	"heifeng", "huashan", "mafeng", "paiyun", "path1",
	"path2", "path3", "path4", "path5", "path6", "shaowu", });

	if(!arg)
		return notify_fail("你要伏击谁？\n");

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	if(me->query("age") <= PROTECT_AGE)
		return notify_fail("这么小的年龄就干这种事情，以后再说吧。\n");

	if(!who = find_player(arg))
		return notify_fail("游戏里好像没有这么个人。\n");
	if(who == me)
		return notify_fail("你不会是要伏击你自己吧？\n");

	env = environment(me);
	if(!env)
		return notify_fail("你现在连自己在哪都不知道，怎么伏击别人？\n");

	if(env->is_player_home())
		return notify_fail("在"+((env->query("master_id") == me->query("id"))?"自己":"别人")
			+"的家里怎么能做这种事情？\n");

	if( env->query("invalid_fuji") )
		return notify_fail("这里难以藏身。\n");

	if( member_array(domain_file(base_name(env)),valid_domain) < 0 )
		return notify_fail("此地不适合藏身打埋伏。\n");

	if(!env->query("outdoors"))
		return notify_fail("此处难以藏身打埋伏。\n");

	if(who->query("age") <= PROTECT_AGE)
		return notify_fail("对方年龄太小，还处在保护之中。\n");

	if(mapp(ey = me->query("enyi_class"))
	&& sizeof(ey)
	&& (geteuid(who) != ey["id"]) )
		return notify_fail("你正肩负着仁义庄的重托，没时间做别的事情呢。\n");

	write("你隐身暗处，专等着 "+who->name(1)+" 到来给他出其不意的一击。\n");
	tell_room(env,me->name()+"四下看了看，走道路旁躲了起来。\n",({me}));

	me->start_busy(2);
	me->set_leader(0);
	me->delete_temp("guardling");
	me->set_temp("fuji_player",arg);
	me->set("env/invisibility",1);
	environment(me)->add("fuji/"+arg,({ me }));
	return 1;
}

int help(object me)
{
        write(@TEXT
指令格式：fuji <某人>

此命令可以让你在荒郊野外藏身于
一个隐秘之处伏击某人，在你伏击
的时候别人无法看到你，你为了不
暴露自己也有很多事情不能作了，
一旦被你伏击的人落入你的伏击圈
你会立刻跳出来拦截住对方战斗。

相关命令：unfuji

此设想由 elon 提供，特此感谢！
TEXT
        );
        return 1;
}