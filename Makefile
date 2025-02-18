
all:
	$(MAKE) -C philo all


clean:
	$(MAKE) -C philo clean


.PHONY: all, clean
.DEFAULT_GOAL = all
