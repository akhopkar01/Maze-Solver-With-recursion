.PHONY: clean All

All:
	@echo "----------Building project:[ Assignment - Debug ]----------"
	@cd "Assignment" && "$(MAKE)" -f  "Assignment.mk"
clean:
	@echo "----------Cleaning project:[ Assignment - Debug ]----------"
	@cd "Assignment" && "$(MAKE)" -f  "Assignment.mk" clean
